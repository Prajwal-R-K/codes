from flask import Flask  # Flask is class

# An instance of this class will be our WSGI(web server gateway interface) application.

app = Flask(__name__)  # create an instance of this class

@app.route("/")  # use the route() decorator to tell Flask what URL should trigger our function.
def hello_world():
    return "<p>Hello, World!</p>"

if __name__ == "__main__":  
    app.run()



# app.run(debug='True') -- Any changes made in the code will be reflected in the server without running once again
# The app.run(debug=True) line ensures that the server runs in debug mode,
#  which provides useful error messages and automatically restarts the server on code changes.