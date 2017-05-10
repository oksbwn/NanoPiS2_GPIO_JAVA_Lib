package in.weargenius.gpio;
import java.io.IOException;

import in.weargenius.nativeloader.NativeUtils;

public class gpio {

    public native int GPIOExport(int pin);
	public native int GPIOUnexport(int pin);
	public native int GPIODirection(int pin, int dir);
	public native int GPIORead(int pin);
	public native boolean isGPIOExported(int pin);
	public native int GPIOWrite(int pin, int value);
	
	private int pin;
    static {
        try {
			NativeUtils.loadLibraryFromJar("/resources/gpio.so");
			//System.load("/root/Desktop/pi4j/native/gpio.so");

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
    }
    public gpio(int pin){
    	if(pin!=0)
    		this.pin=pin;
    }
    public gpio provisionDigitalInputPin(int pin){
    	if(isGPIOExported(pin)){
    		System.out.println("Pin already in USE.");
			GPIOUnexport(pin);
    	}
    	GPIOExport(pin);
    	GPIODirection(pin,0);
	  	return new gpio(pin);
    }
    public gpio provisionDigitalOutputPin(int pin){

    	if(isGPIOExported(pin)){
    		System.out.println("Pin already in USE.");
			GPIOUnexport(pin);
    	}
  	  	GPIOExport(pin);
  	  	GPIODirection(pin,1);
  	  	return new gpio(pin);
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
    public int high(){
    	return GPIOWrite(pin,1);
    }
    public int low(){
    	return GPIOWrite(pin,0);
    }
	public int close(){
		return GPIOUnexport(this.pin);
	}
}