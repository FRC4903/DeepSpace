class Drivetrain
{
private:
	TalonSRX FL, FR, RL, RR;

	double getPi();
	double getRealAngle(double degAng);
	double getWheelPower(double and, bool A);
public:
	Drivetrain(TalonSRX fl, TalonSRX fr, TalonSRX rl, TalonSRX rr);

	void turn (double moveAngle);
	void turnTo (double moveAngle);

	void moveOrTurn(double x, double y, double turnMag, double moderator);

}