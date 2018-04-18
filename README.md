# Home_Atomation_tcp
IoT with TCP Model 

 HOME  ATOMATION  WITH  NodeMCU Node-Red

I’ll program the ESP8266 using the Arduino IDE 1.8.5. In order to upload code to your ESP8266 using the Arduino IDE 1.8.5, you need to install the ESP8266 add-on. You’ll also need to install two additional libraries to have everything ready for your ESP8266. You need to install the DHT library.


GOURAB DEY
 
•	HARDWARE REQURED:
		 We are Using a laptop and a NodeMCU. It is mainly use to upload code to the NodeMCU and control sensor & devise. Other hardwares are LEDs, Jumper wires, Temperature & Humidity sensor(DHT11) & lastly a breadboard where use connect all those things in a one circuit. Not only hardware some software are also have been used.
1.	NodeMCU: NodeMCU is an open source IoT platform. It includes firmware which runs on the ESP8266 Wi-Fi SoC, and hardware which is based on the ESP-12 module. The term "NodeMCU" by default refers to the firmware rather than the development kits. The firmware uses the Lua scripting language. It is based on the eLua project. It uses many open source projects, such as lua-cjson, and spiffs.

2.	Temperature & Humidity sensor (DHT11): A humidity sensor senses, measures and regularly reports the relative humidity in the air. It measures both moisture and air temperature. Expressed as a percent, is the ratio of actual moisture in the air to the highest amount of moisture air at that temperature can hold. Its technology ensures the high reliability and excellent long-term stability. A high-performance 8-bit microcontroller is connected. It has excellent quality, fast response, anti-interference ability and high cost performance advantages.
3.	Jumper wires: A jump wire is an electrical wire, or group of them in a cable, with a connector or pin at each end, which is normally used to interconnect the components of a breadboard or other prototype or test circuit, internally or with other equipment or components, without soldering. Individual jump wires are fitted by inserting their "end connectors" into the slots provided in a breadboard, the header connector of a circuit board, or a piece of test equipment.
4.	LED: Light emitting diodes (LEDs) are semiconductor light sources. The light emitted from LEDs varies from visible to infrared and ultraviolet regions. They operate on low voltage and power. LEDs are one of the most common electronic components and are mostly used as indicators in circuits. LEDs are a particular type of diode that convert electrical energy into light. In fact. In short, LEDs are like tiny lightbulbs. However, LEDs require a lot less power to light up by comparison. They’re also more energy efficient.

5.	 Breadboard: A breadboard is a solderless device for temporary prototype with electronics and test circuit designs. Most electronic components in electronic circuits can be interconnected by inserting their leads or terminals into the holes and then making connections through wires where appropriate. The breadboard has strips of metal underneath the board and connect the holes on the top of the board. This makes it easy to use for creating temporary prototypes and experimenting with circuit design. For this reason, solderless breadboards are also popular with students and in technological education.

•	PCB Layout:  This is PCB design of our circuit. 
•	DESIGN IDEA OF THE PROJECT:
IOT Layer Architecture
Application
	HTTP, MQTT,NODE-RED etc.
Management service
	AWS, Azure etc.
Gateway
	WifiRouter, LoRaWAN.
Sensor network &community	Edge devices, local connectivity, Sensors,etc.



•	SOFTWARE STACK:
       We are mainly use Arduino IDE 1.8.5. Other 
       Software are NODE-RED, MQTT box. 

1.	Arduino IDE 1.8.5: The Arduino integrated development environment (IDE) is a cross-platform application. The Arduino IDE supports the languages C and C++. The Arduino IDE supplies a software library from the Wiring project. It originated from the IDE for the languages Processing and Wiring. It includes a code editor with features such as automatic indenting, brace matching, syntax highlighting, provides simple one-click mechanisms to compile and upload programs to an Arduino board. You also need to select the right board on Arduino IDE:
1) Go to Tools and select “NodeMCU 1.0 (ESP-12E Module)”.
2) Select your ESP port number under the Tools > Port > COM4 (in my case)

2.	MQTT Box:  MQTT Box  (Message Queuing Telemetry Transport)  is a application. MQTT Box enables you to create MQTT clients to publish or subscript topics, create MQTT virtual device networks, load test MQTT devices or brokers and much more.

	MQTT Client: Publish/Subscribe decouples a client, which is sending a particular message (called publisher) from another client (or more clients), which is receiving the message (called subscriber). Any publisher or subscriber that connects to the centralized broker over a network is considered to be the client. It’s important to note that there are servers and clients in MQTT. Both publishers and subscribers are called as clients since they connect to the centralized service. Clients can be persistent or transient. Persistent clients maintain a session with the broker while transient clients are not tracked by the broker.
	MQTT Broker: The broker is the software that receives all the messages from the publishing clients and sends them to the subscribing clients. It holds the connection to persistent clients.
	MQTT Topic: A topic in MQTT is an endpoint to that the clients connect. It acts as the central distribution hub for publishing and subscribing messages. A topic is created before the publisher and subscriber connect to the endpoint. In MQTT, a topic is a well-known location for the publisher and subscriber. It’s created on the fly when either of the clients establish the connection with the broker.
3.	Node-Red: Node-RED is a flow-based development tool developed originally by IBM for wiring together hardware devices, APIs and online services as part of the Internet of Things. Node-RED provides a browser-based flow editor, which can be used to create JavaScript functions. Elements of applications can be saved or shared for re-use. The runtime is built on Node.js. The flows created in Node-RED are stored using JSON. IBM contributed Node-RED as an open source JS Foundation project.

•	CHALLENGES:
The main challenges are to error of code & output. Sometimes logic’s of code is right but output is wrong. Another problem is jumper wire. All jumper wire are not same. Which jumper wire I want that I not get. Here network is not good. It make some issues.
•	CODE LOGIC:
Code logic are given

