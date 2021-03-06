//
// Copyright (C) 2006-2018 Christoph Sommer <sommer@ccs-labs.org>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#ifndef VEHICLEOBSTACLEFADING_H_
#define VEHICLEOBSTACLEFADING_H_

#include "veins/base/phyLayer/AnalogueModel.h"
#include "veins/base/modules/BaseWorldUtility.h"
#include "veins/modules/obstacle/VehicleObstacleControl.h"
#include "veins/base/utils/Move.h"
#include "veins/base/messages/AirFrame_m.h"

using Veins::AirFrame;
using Veins::VehicleObstacleControl;

#include <cstdlib>

namespace Veins {

/**
 * @brief Basic implementation of a VehicleObstacleShadowing that uses
 * SimplePathlossConstMapping (that is subclassed from SimpleConstMapping) as attenuation-Mapping.
 *
 * @ingroup analogueModels
 */
class VehicleObstacleShadowing : public AnalogueModel {
protected:
    /** @brief reference to global VehicleObstacleControl instance */
    VehicleObstacleControl& vehicleObstacleControl;

    /** @brief carrier frequency needed for calculation */
    double carrierFrequency;

    /** @brief Information needed about the playground */
    const bool useTorus;

    /** @brief The size of the playground.*/
    const Coord& playgroundSize;

    /** @brief Whether debug messages should be displayed. */
    bool debug;

public:
    /**
     * @brief Initializes the analogue model. myMove and playgroundSize
     * need to be valid as long as this instance exists.
     *
     * The constructor needs some specific knowledge in order to create
     * its mapping properly:
     *
     * @param vehicleObstacleControl reference to global VehicleObstacleControl module
     * @param carrierFrequency the carrier frequency
     * @param useTorus information about the playground the host is moving in
     * @param playgroundSize information about the playground the host is moving in
     * @param debug display debug messages?
     */
    VehicleObstacleShadowing(VehicleObstacleControl& vehicleObstacleControl, double carrierFrequency, bool useTorus, const Coord& playgroundSize, bool debug);

    /**
     * @brief Filters a specified Signal by adding an attenuation
     * over time to the Signal.
     */
    virtual void filterSignal(Signal* signal, const Coord& sendersPos, const Coord& receiverPos) override;

    virtual bool neverIncreasesPower() override
    {
        return true;
    }
};

} // namespace Veins

#endif /*PATHLOSSMODEL_H_*/
