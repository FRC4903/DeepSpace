class Climber 
{
private:
	TalonSRX frontClimb, backClimb, backDrive;
	double climbMod;
	bool enabled;
	const double backAngle;
public:
	Climber(TalonSRx FClimb, TalonSRX BClimb, TalonSRX BDrive);

	void toggleDisable();

	void frontDown(moderator);
	void frontUp(moderator);

	void backDown(moderator);
	void backUp(moderator);

	void drive(moderator);
}