package in.weargenius.gpio;
import java.io.IOException;

import in.weargenius.nativeloader.NativeUtils;

public class DigitalOutputPin{
	public native int GPIOWrite(int pin, int value);
	public native int GPIOUnexport(int pin);
	
	private int pin=0;
	
	static {
        try {
			NativeUtils.loadLibraryFromJar("/resources/gpio.so");
			//System.load("/root/Desktop/pi4j/native/gpio.so");

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
    }
		
    public DigitalOutputPin(int pin){
    		this.pin=pin;
    }
	public int high(){
    	return GPIOWrite(pin,1);
    }
    public int low(){
    	return GPIOWrite(pin,0);
    }
    public int close(){
    	return GPIOUnexport(pin);
    }
}