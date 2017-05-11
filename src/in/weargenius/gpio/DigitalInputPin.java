package in.weargenius.gpio;
import java.io.IOException;

import in.weargenius.nativeloader.NativeUtils;
public class DigitalInputPin{
	public native int GPIORead(int pin);
	public native int GPIOUnexport(int pin);
	
	private int pin=0;
	
    public DigitalInputPin(int pin){
    		this.pin=pin;
    }
	static {
        try {
			NativeUtils.loadLibraryFromJar("/resources/gpio.so");
			//System.load("/root/Desktop/pi4j/native/gpio.so");

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
    }
	
    public boolean isHigh(){
    	if( GPIORead(pin)==1)
    		return true;
    	else 
    		return false;
    }   
    public boolean isLow(){
    	if( GPIORead(pin)==0)
    		return true;
    	else 
    		return false;
    }
	
    public int close(){
    	return GPIOUnexport(pin);
    }
}