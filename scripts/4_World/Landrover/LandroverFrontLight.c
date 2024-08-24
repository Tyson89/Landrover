class LandroverFrontLight : CarLightBase
{
	void LandroverFrontLight()
	{
		m_SegregatedBrightness = 10;
		m_SegregatedRadius = 180;
		m_SegregatedAngle = 110;
		m_SegregatedColorRGB = Vector(1.0, 0.9, 0.9);
		
		m_AggregatedBrightness = 20;
		m_AggregatedRadius = 200;
		m_AggregatedAngle = 120;
		m_AggregatedColorRGB = Vector(1.0, 0.9, 0.9);
		
		FadeIn(0.3);
		SetFadeOutTime(0.25);
		
		SegregateLight();
	}
};