/*
 * Copyright 2000-2015 Rochus Keller <mailto:rkeller@nmr.ch>
 *
 * This file is part of the CARA (Computer Aided Resonance Assignment,
 * see <http://cara.nmr.ch/>) NMR Application Framework (NAF) library.
 *
 * The following is the license that applies to this copy of the
 * library. For a license to use the library under conditions
 * other than those described here, please email to rkeller@nmr.ch.
 *
 * GNU General Public License Usage
 * This file may be used under the terms of the GNU General Public
 * License (GPL) versions 2.0 or 3.0 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in
 * the packaging of this file. Please review the following information
 * to ensure GNU General Public Licensing requirements will be met:
 * http://www.fsf.org/licensing/licenses/info/GPLv2.html and
 * http://www.gnu.org/copyleft/gpl.html.
 */

#if !defined(AFX_SPINLINKVIEW_H__31FDF13A_48F3_4768_8E37_8FBA496D9506__INCLUDED_)
#define AFX_SPINLINKVIEW_H__31FDF13A_48F3_4768_8E37_8FBA496D9506__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <SpecView/SpecView.h>
#include <Spec/SpinSpace.h>
#include <QColor>
#include <Root/SymbolString.h>

namespace Spec
{
	class SpinLinkView : public SpecView
	{
	public:
		void showVerti( bool );
		bool showVerti() const { return d_showVerti; }
		void clear();
		void setColor( QColor );
		QColor getColor() const { return d_clr; }
		void setThick( Lexi::Twips );
		Lexi::Twips getThick() const { return d_thick; }
		void addLabel( Root::SymbolString );
		void setLabels( const Root::SymbolSet& );
		SpinLinkView(SpecViewer*, SpinSpace*, QColor = Qt::darkRed);
		//* Override
		void draw( Canvas&, const Lexi::Allocation& );
	protected:
		virtual ~SpinLinkView();
		void handle( Root::Message & );
	private:
		Root::Ref<SpinSpace> d_model;
		QColor d_clr;
		Root::SymbolSet d_labels;
		Lexi::Twips d_thick;
		bool d_showVerti;
	};
}

#endif // !defined(AFX_SPINLINKVIEW_H__31FDF13A_48F3_4768_8E37_8FBA496D9506__INCLUDED_)
