from flask import Flask
from flask import abort, redirect, url_for
app = Flask(__name__)

@app.route('/')
def index():
    return redirect(url_for('login'))

@app.route('/login')
def login():
    return "Executed"

if __name__ == "__main__":
    app.run(debug=True)