from markupsafe import escape
from flask import Flask

app = Flask(__name__) 
@app.route("/")  # use the route() decorator to tell Flask what URL should trigger our function.
def hello_world():
    return "<p>Hello, World!</p>"

# Use the route() decorator to bind a function to a URL.

@app.route('/index')
def index():
    return 'Index Page'

@app.route('/hello')
def hello1():
    return 'Hello, World'

if __name__ == "__main__":
    app.run()