
import matplotlib.pyplot as plt



plt.ion()
fig, ax = plt.subplots()
ax.set_title('Light Sensor')
ax.set_xlabel('Time')
ax.set_ylabel('Light Intensity')

x, y = [], []
line, = ax.plot(x, y)

while True:
    try:
        data=[20,28,90,65]
        x.append(len(x))
        y.append(data)

        line.set_data(x, y)

        ax.relim()
        ax.autoscale_view(True,True,True)

        fig.canvas.draw()
        fig.canvas.flush_events()

    except KeyboardInterrupt:
        break