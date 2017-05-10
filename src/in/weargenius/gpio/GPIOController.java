package in.weargenius.gpio;

public class GPIOController {
	private static gpio gpioController =null;
	public static gpio getInstance(){
		
		if(gpioController==null)
			gpioController= new gpio(0);
		return gpioController;
	}
}
