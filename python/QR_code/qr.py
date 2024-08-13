import qrcode

name=input("Enter the qr code name you need :")
website_link = input("Enter the Link to create QR CODE:")

qr = qrcode.QRCode(version = 1, box_size = 5, border = 5)
qr.add_data(website_link)
qr.make()

img = qr.make_image(fill_color = 'black', back_color = 'white')
img.save(name+'.png')  