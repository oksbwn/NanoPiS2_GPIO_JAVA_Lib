cd /root/Desktop/NP4J/

ant compile-jar-classes
 
cd bin/ 

javah -d /root/Desktop/NP4J/src/native in.weargenius.gpio.gpio
javah -d /root/Desktop/NP4J/src/native in.weargenius.gpio.DigitalInputPin
javah -d /root/Desktop/NP4J/src/native in.weargenius.gpio.DigitalOutputPin
   

gcc /root/Desktop/NP4J/src/native/gpio.c -fPIC -I /usr/lib/jvm/java-7-openjdk-armhf/include -I /usr/lib/jvm/java-7-openjdk-armhf/include/linux  -I /root/Desktop/NP4J/src/ -shared -o /root/Desktop/NP4J/src/resources/gpio.so

cd /root/Desktop/NP4J/src/native/

gcc -c /root/Desktop/NP4J/src/native/gpio.c -fPIC -I /usr/lib/jvm/java-7-openjdk-armhf/include -I /usr/lib/jvm/java-7-openjdk-armhf/include/linux  -I /root/Desktop/NP4J/src/

gcc -c /root/Desktop/NP4J/src/native/DigitalOutputPin.c -fPIC -I /usr/lib/jvm/java-7-openjdk-armhf/include -I /usr/lib/jvm/java-7-openjdk-armhf/include/linux  -I /root/Desktop/NP4J/src/

gcc -c /root/Desktop/NP4J/src/native/DigitalInputPin.c -fPIC -I /usr/lib/jvm/java-7-openjdk-armhf/include -I /usr/lib/jvm/java-7-openjdk-armhf/include/linux  -I /root/Desktop/NP4J/src/

gcc -shared -o /root/Desktop/NP4J/src/resources/gpio.so gpio.o DigitalOutputPin.o DigitalInputPin.o

cd /root/Desktop/NP4J/

ant build-jar
