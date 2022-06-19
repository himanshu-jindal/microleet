from project import app, db
from project.forms import LoginForm, RegistrationForm
from flask import render_template, redirect, url_for, flash
from project.models import User
from flask_login import login_user, logout_user, login_required

@app.route('/')
def home():
    return render_template('home.html')


@app.route('/register', methods=['POST', 'GET'])
def register():
    form = RegistrationForm()

    if form.validate_on_submit():
        username = form.username.data
        email = form.email.data
        user_by_username = User.query.filter_by(username=username).first()
        user_by_email = User.query.filter_by(email=email).first()

        msg = "duplicate username/email"
        if user_by_username or user_by_email:
            return render_template('error.html', msg=msg)

        user_obj = User(username, email, form.password.data)
        db.session.add(user_obj)
        db.session.commit()
        all_users = User.query.get(user_obj.id)
        return render_template('all_users.html', all_users=all_users)

    return render_template('register.html', form=form)

@app.route('/login', methods=['POST', 'GET'])
def login():
    form = LoginForm()
    print("palvika")
    if form.validate_on_submit():
        print("dharampal")
        email_recv = form.email.data
        user_from_db = User.query.filter_by(email=email_recv).first()
        print(user_from_db)
        msg = "No user with this name"
        if user_from_db is None:
            return render_template('error.html', msg=msg)
        if user_from_db.check_password(form.password.data):
            print("logged him")
            login_user(user_from_db)
            flash('Logged in successfully.')
            return render_template('welcome.html', email=email_recv)
        else:
           return render_template('error.html', msg=msg) 

    return render_template('login.html', form=form)

'''
@app.route('/welcome')
@login_required
def welcome():
    return render_template('welcome.html')
'''
@app.route('/logout')
@login_required
def logout():
    logout_user()
    flash('You logged out!')
    return render_template('home.html')


if __name__ == '__main__':
    app.run(debug=True)