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

#ifndef SPEEDCONTROLSWIDGET_H
#define SPEEDCONTROLSWIDGET_H

#include <QWidget>
#include <QtGui>

class SpeedControlsWidget : public QGroupBox
{
	Q_OBJECT
	
	public:
		SpeedControlsWidget();

	signals:
	
	public slots:
	
	private:
		QVBoxLayout *speedControlsLayout;
		QSlider *speedGlobal;

};

#endif