from flask import Flask, request, url_for, render_template, redirect

app = Flask(__name__)

def show_the_login_form():
    return render_template('login2  .html')

def do_the_login():
    username = request.form['username']
    password = request.form['password']
    if username == 'admin' and password == '1234':  # replace with real authentication logic
        return redirect(url_for('dashboard'))
    else:
        return "Invalid credentials", 401

@app.route('/')
def index():
    return 'index'

@app.get('/login')
def login_get():
    return show_the_login_form()

@app.post('/login')
def login_post():
    return do_the_login()

@app.route('/dashboard')
def dashboard():
    return "Welcome to the dashboard!"

if __name__ == "__main__":
    app.run(debug=True)
