from flask import Flask, request, render_template

aapp = Flask(__name__)

@aapp.route('/')
def master():
    return render_template('master.html')

@aapp.route('/report')
def report():
    username = request.args.get('username')
    if not username:
        return render_template('basic.html')

    c1='Username is missing a lowecase character' 
    c2='Username is missing a uppercase character'
    c3='Username is missing a number in the end'

    for letter in username:
        if  not c1 and not c2:
            break
        if letter.islower():
            c1=''
        if letter.isupper():
            c2=''
    
    if username[-1].isdigit():
        c3 = ''
    return render_template('report.html', c1=c1, c2=c2, c3=c3)





if __name__ == '__main__':
    aapp.run(debug="True")