import paho.mqtt.client as mqtt
import matplotlib.pyplot as plt 
from plot_data import DataPlot, RealtimePlot

fig, axes = plt.subplots()
plt.title('Data from temperature sensor')

data = DataPlot()
dataPlotting= RealtimePlot(axes)


count = 0


def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))

    client.subscribe("/topic/temp")
    client.subscribe("/topic/light")
    
    
def on_message(client, userdata, msg):
    if(msg.topic == '/topic/temp'): 
        temp = str(msg.payload)
        temp = temp.replace("b", '')
        temp = int(temp.replace("'", ''))
        print("Temp: " + str(temp))
        global count
        count+=0.5
        data.add(count, temp , temp)
        dataPlotting.plot(data)
        plt.pause(0.001)
        
         
        
    # elif (msg.topic == '/topic/light'):
    #     light = str(msg.payload)
    #     light = light.replace("b", '')
    #     light = int(light.replace("'", ''))
    #     print("Light: " + str(light))

        

        
        
        
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("10.230.24.108", 1883, 60)
client.loop_forever()