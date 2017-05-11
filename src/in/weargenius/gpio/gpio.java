package in.weargenius.gpio;
import java.io.IOException;

import in.weargenius.nativeloader.NativeUtils;

public class gpio {

    public native int GPIOExport(int pin);
	public native int GPIODirection(int pin, int dir);
	public native boolean isGPIOExported(int pin);
	public native int GPIOUnexport(int pin);
	
    static {
        try {
			NativeUtils.loadLibraryFromJar("/resources/gpio.so");
			//System.load("/root/Desktop/pi4j/native/gpio.so");

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
    }
	public DigitalInputPin provisionDigitalInputPin(int pin){
    	if(isGPIOExported(pin)){
    		System.out.println("Pin already in USE.");
			GPIOUnexport(pin);
    	}
    	GPIOExport(pin);
    	GPIODirection(pin,0);
	  	return new DigitalInputPin(pin);
    }
    public DigitalOutputPin provisionDigitalOutputPin(int pin){

    	if(isGPIOExported(pin)){
    		System.out.println("Pin already in USE.");
			GPIOUnexport(pin);
    	}
  	  	GPIOExport(pin);
  	  	GPIODirection(pin,1);
  	  	return new DigitalOutputPin(pin);
    }
}