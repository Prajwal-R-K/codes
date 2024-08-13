from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html') # see that ther is "static" folder and in "index.html" the "style.css" is used  ( flask_library\static\style.css )

@app.route('/submit', methods=['POST'])
def submit_form():
    username = request.form.get('username')
    password = request.form.get('password')
    message = request.form.get('message')
    
    # Process the form data (e.g., save to database, send an email, etc.)
    # For demonstration purposes, just printing the data:
    print(f"Username: {username}, Password: {password}, Message: {message}")
    
    return "Form submitted successfully!"

if __name__ == "__main__":
    app.run(debug=True)


# The output is printed in the terminal