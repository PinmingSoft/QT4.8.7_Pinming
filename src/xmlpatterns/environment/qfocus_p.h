/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef Patternist_Focus_H
#define Patternist_Focus_H

#include "qdelegatingdynamiccontext_p.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short A DynamicContext that maintains the focus, a sequence
     * of items.
     *
     * Focus implements both the outer and inner focus. The focus is one of
     * the things that characterizes the XPath language. The focus is what's
     * iterated over in a predicate, whose current item can be received
     * via the context item expression, <tt>.</tt>(the dot),
     * and whose size is retrievable via the function <tt>fn:last()</tt>.
     *
     * @author Frans Englich <frans.englich@nokia.com>
     */
    class Focus : public DelegatingDynamicContext
    {
    public:
        Focus(const DynamicContext::Ptr &prevContext);

        virtual xsInteger contextPosition() const;
        virtual Item contextItem() const;
        virtual xsInteger contextSize();

        virtual void setFocusIterator(const Item::Iterator::Ptr &it);
        virtual Item::Iterator::Ptr focusIterator() const;

        /**
         * If there is no top level expression that sets the current item,
         * the focus should be used. This implementation ensures that.
         */
        virtual Item currentItem() const;

    private:
        Item::Iterator::Ptr m_focusIterator;
        xsInteger           m_contextSizeCached;
    };
}

QT_END_NAMESPACE

QT_END_HEADER

#endif
