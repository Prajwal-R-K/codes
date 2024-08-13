from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html') 

@app.route('/submit', methods=['POST'])
def submit_form():
    username = request.form.get('username')
    password = request.form.get('password')
    message = request.form.get('message')

    return f"Request successfully! {username} {password} {message}"

if __name__ == "__main__":
    app.run(debug=True)