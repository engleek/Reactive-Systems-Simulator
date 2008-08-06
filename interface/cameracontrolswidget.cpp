/*******************************************************************************************
 **
 **    Copyright 2008 Simon & Humphries
 **
 **    This file is part of the Reactive Systems Simulator.
 **
 **    The Reactive Systems Simulator is free software: you can redistribute it and/or modify
 **    it under the terms of the GNU General Public License as published by
 **    the Free Software Foundation, either version 3 of the License, or
 **    (at your option) any later version.
 **
 **    The Reactive Systems Simulator is distributed in the hope that it will be useful,
 **    but WITHOUT ANY WARRANTY; without even the implied warranty of
 **    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **    GNU General Public License for more details.
 **
 **    You should have received a copy of the GNU General Public License
 **    along with the Reactive Systems Simulator .  If not, see <http://www.gnu.org/licenses/>.
 **
 ********************************************************************************************/

#include "cameracontrolswidget.h"

CameraControlsWidget::CameraControlsWidget()
{
	topView = new QRadioButton(tr("Top view"));
	followCam = new QRadioButton(tr("Follow"));
	circlingCam = new QRadioButton(tr("Circle map"));
	teamCam = new QRadioButton(tr("Follow team"));
	
	topView->setChecked(true);
	
	cameraControlsLayout = new QVBoxLayout;
	cameraControlsLayout->addWidget(topView);
	cameraControlsLayout->addWidget(followCam);
	cameraControlsLayout->addWidget(circlingCam);
	cameraControlsLayout->addWidget(teamCam);
	cameraControlsLayout->addStretch(1);
	setLayout(cameraControlsLayout);
}
