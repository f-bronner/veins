//
// Copyright (C) 2018 Christoph Sommer <sommer@ccs-labs.org>
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
#ifndef TESTUTILS_AIRFRAME_H
#define TESTUTILS_AIRFRAME_H

#include <omnetpp.h>
#include "veins/base/messages/AirFrame_m.h"

Veins::AirFrame createAirframe(double centerFreq, double bandwidth, omnetpp::simtime_t start, omnetpp::simtime_t length, double power)
{
    Veins::Signal s(Veins::Spectrum({centerFreq - 5e6, centerFreq, centerFreq + 5e6}), start, length);
    s(centerFreq - 5e6) = power;
    s(centerFreq) = power;
    s(centerFreq + 5e6) = power;

    Veins::AirFrame frame;
    frame.setSignal(s);
    return frame;
}

#endif
