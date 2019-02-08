class Elevator 
{
private:
	TalonSRX liftTalon, grabTalon;
	double liftMod;
public:
	Elevator(TalonSRX liftTalon, TalonSRX grabTalon );
	
	void lift(double moderator);
	void descend(double moderator);

	void grab(double moderator);
	void release(double moderator);
}