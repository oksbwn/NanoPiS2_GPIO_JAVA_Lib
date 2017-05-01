public class gpio {

    public native int GPIOExport(int pin);
	public native int GPIOUnexport(int pin);
	public native int GPIODirection(int pin, int dir);
	public native int GPIORead(int pin);
	public native boolean isGPIOExported(int pin);
	public native int GPIOWrite(int pin, int value);
	
    static {
        System.load("/root/Desktop/pi4j/native/gpio.so");
    }

    public static void main(String[] args) {
		gpio pin = new gpio();
		if(!pin.isGPIOExported(104)){
			System.out.println("Pin not in USE.");
			pin.GPIOExport(104);
		}else{
			System.out.println("Pin Alrady in use.");
			pin.GPIOUnexport(104);
			pin.GPIOExport(104);
		}
		pin.GPIODirection(104,1);
		for(int i=0;i<20;i++){
			try{
				pin.GPIOWrite(104,0);
				Thread.sleep(2000);
				pin.GPIOWrite(104,1);
				Thread.sleep(2000);
			}catch(Exception e){
			e.printStackTrace();
		 }
		}
		pin.GPIOUnexport(104);
    }
}