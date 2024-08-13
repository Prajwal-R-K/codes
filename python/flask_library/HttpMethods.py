from flask import Flask, request, url_for, render_template, redirect

app = Flask(__name__)

@app.route('/')
def index():
    return 'index'

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        return do_the_login()
    else:
        return show_the_login_form()

def do_the_login():
    username = request.form['username']
    password = request.form['password']
    if username == 'admin' and password == '1234':  # replace with real authentication logic
        return redirect(url_for('dashboard'))
    else:
        return "Invalid credentials", 401

def show_the_login_form():
    return render_template('login.html')

@app.route('/dashboard')
def dashboard():
    return "Welcome to the dashboard!"

if __name__ == "__main__":
    app.run(debug=True)



"""
The GET and POST methods are part of the HTTP protocol, which is the foundation of data communication on the web.
In Flask, these methods are used to handle different types of HTTP requests.
"""
# GET Method 
"""
The GET method is used to request data from a specified resource. 
Requests using GET should only retrieve data and should have no other effect on the data.

When Executed: A GET request is executed when a user accesses a URL in their browser, follows a link, or submits a form without the method attribute (which defaults to GET).
Example: When a user visits the login page at http://localhost:5000/login.

"""

# POST Method
"""
The POST method is used to send data to a server to create/update a resource.
The data sent to the server with POST is stored in the request body.

When Executed: A POST request is executed when a user submits a form with the method="post" attribute.
Example: When a user submits the login form at http://localhost:5000/login.

"""