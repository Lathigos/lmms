/*
 * TimeDisplayWidget.h - widget for displaying current playback time
 *
 * Copyright (c) 2014 Ruben Ibarra
 * Copyright (c) 2014 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 *
 * This file is part of LMMS - https://lmms.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */

#ifndef _TIME_DISPLAY_WIDGET
#define _TIME_DISPLAY_WIDGET

#include <QWidget>
#include <QGridLayout>

#include "IntegerDisplayWidget.h"

class QLabel;

class TimeDisplayWidget : public QWidget
{
	Q_OBJECT
public:
	TimeDisplayWidget( QWidget * _parent );
	virtual ~TimeDisplayWidget() = default;


protected:
	void mousePressEvent( QMouseEvent* mouseEvent ) override;


private slots:
	void updateTime();


private:
	enum DisplayModes
	{
		MinutesSeconds,
		BarsTicks,
		DisplayModeCount
	};
	typedef DisplayModes DisplayMode;

	void setDisplayMode( DisplayMode displayMode );

	DisplayMode m_displayMode;
	QGridLayout m_spinBoxesLayout;
	IntegerDisplayWidget m_majorLCD;
	IntegerDisplayWidget m_minorLCD;
	IntegerDisplayWidget m_milliSecondsLCD;
	
	QLabel * m_majorLabel;
	QLabel * m_minorLabel;
	QLabel * m_milliSecondsLabel;

} ;

#endif
