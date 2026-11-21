#pragma once

namespace NovaE {
	class DeltaTime {
	public:
		static void Update();
		static float Get();
	private:
		static double m_LastTime;
		static float m_DeltaTime;
	};
}