from flask import Flask, render_template, redirect, url_for

app = Flask(__name__)

# Redirect from '/' to '/hello'
@app.route('/')
def index():
    return redirect(url_for('hello'))

# Dynamic route for '/hello/' and '/hello/<name>'
@app.route('/hello/')
@app.route('/hello/<name>')
def hello(name=None):
    return render_template('hello.html', person=name)

if __name__ == "__main__":
    app.run(debug=True)


# If i have not given this(block) 
"""
@app.route('/')
def index():
    return redirect(url_for('hello'))
"""
# Then you should give excplicitly endpoint '/hello' in the url