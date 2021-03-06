//
// Copyright (C) 2018 Dominik S. Buse <buse@ccs-labs.org>
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
#ifndef DUMMYANALOGUEMODEL_H_
#define DUMMYANALOGUEMODEL_H_

#include "veins/base/phyLayer/AnalogueModel.h"

namespace Veins {

class DummyAnalogueModel : public AnalogueModel {
protected:
    const double factor;

public:
    DummyAnalogueModel(double factor)
        : factor(factor)
    {
    }

    void filterSignal(Signal* signal, const Coord& sendersPos, const Coord& receiverPos) override
    {
        signal->addUniformAttenuation(factor);
    }
};
} // namespace Veins

#endif /*DUMMYANALOGUEMODEL_H_*/
