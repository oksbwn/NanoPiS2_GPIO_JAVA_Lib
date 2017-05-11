# NanoPiS2_GPIO_JAVA_Lib
A JAVA Library to access GPIO for Nano Pi S2 . Using JNI.

Beginning of the project so don't expect professional work. You can contribute to the repo so that others can also use it.


gcc gpio.c -fPIC -I /usr/lib/jvm/java-7-openjdk-armhf/include -I /usr/lib/jvm/java-7-openjdk-armhf/include/linux  -I /root/Desktop/java -I /root/Desktop/java/includes -shared -o gpio.so



cd /root/Desktop/pi4j/native/JAVA_lib_files/bin/ 
javah -d /root/Desktop/pi4j/native/JAVA_lib_files/src/native in.weargenius.gpio.gpio     

-------------
javac -d /root/Desktop/pi4j/native/JAVA_lib_files/bin -sourcepath /root/Desktop/pi4j/native/JAVA_lib_files/src /root/Desktop/pi4j/native/JAVA_lib_files/src/in/weargenius/gpio/gpio.java

cd /root/Desktop/pi4j/native/JAVA_lib_files/bin/ 

javah -d /root/Desktop/pi4j/native/JAVA_lib_files/src/native in.weargenius.gpio.gpio    

gcc /root/Desktop/NP4J/src/native/gpio.c -fPIC -I /usr/lib/jvm/java-7-openjdk-armhf/include -I /usr/lib/jvm/java-7-openjdk-armhf/include/linux  -I /root/Desktop/pi4j/native/JAVA_lib_files/src/ -shared -o /root/Desktop/NP4J/src/resources/gpio.so

jar -cvf /root/Desktop/pi4j/native/library/lib.jar /root/Desktop/pi4j/native/JAVA_lib_files

jar cfm /root/Desktop/pi4j/native/library/lib.jar /root/Desktop/pi4j/native/library/manifest -C /root/Desktop/pi4j/native/JAVA_lib_files/bin  -C /root/Desktop/pi4j/native/JAVA_lib_files/src  
