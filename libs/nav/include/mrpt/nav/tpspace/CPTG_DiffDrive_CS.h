/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2016, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+ */
#pragma once

#include <mrpt/nav/tpspace/CPTG_DiffDrive_CollisionGridBased.h>

namespace mrpt
{
  namespace nav
  {
	DEFINE_SERIALIZABLE_PRE_CUSTOM_BASE_LINKAGE(CPTG_DiffDrive_CS, CParameterizedTrajectoryGenerator, NAV_IMPEXP)

	/** A PTG for optimal paths of type "CS", as named in PTG papers.
	 * - **Compatible kinematics**: differential-driven / Ackermann steering
	 * - **Compatible robot shape**: Arbitrary 2D polygon
	 * - **PTG parameters**: use "PTG configurator" tool in the app ReactiveNavigationDemo
	 *
	 *  See "Obstacle Distance for Car-Like Robots", IEEE Trans. Rob. And Autom, 1999.
	 * \note [Before MRPT 1.5.0 this was named CPTG5]
	 *  \ingroup nav_tpspace
	 */
	class NAV_IMPEXP  CPTG_DiffDrive_CS : public CPTG_DiffDrive_CollisionGridBased
	{
		DEFINE_SERIALIZABLE(CPTG_DiffDrive_CS)
	 public:
		CPTG_DiffDrive_CS() : R(0),K(0) {}
		CPTG_DiffDrive_CS(const mrpt::utils::CConfigFileBase &cfg,const std::string &sSection,  const std::string &sKeyPrefix) {
			setParams(cfg,sSection, sKeyPrefix);
		}
		void setParams(const mrpt::utils::CConfigFileBase &cfg,const std::string &sSection,  const std::string &sKeyPrefix) MRPT_OVERRIDE;
		std::string getDescription() const MRPT_OVERRIDE;
		bool PTG_IsIntoDomain( double x, double y ) const MRPT_OVERRIDE;
		void ptgDiffDriveSteeringFunction( float alpha, float t,float x, float y, float phi, float &v, float &w ) const MRPT_OVERRIDE;

	 protected:
		 double R,K;
	};
	DEFINE_SERIALIZABLE_POST_CUSTOM_BASE_LINKAGE(CPTG_DiffDrive_CS, CParameterizedTrajectoryGenerator, NAV_IMPEXP)

  }
}
