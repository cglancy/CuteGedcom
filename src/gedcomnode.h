/**
* Copyright 2017 Charles Glancy
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without restriction, including  without limitation the rights to use, copy,
* modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
* is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
* WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#ifndef GEDCOMNODE_H
#define GEDCOMNODE_H

#include "cutegedcom.h"
#include <QString>
#include <QList>

namespace CuteGedcom
{
    class CUTEGEDCOM_API GedcomNode
    {
    public:
        GedcomNode();
        GedcomNode(const QString &tag, const QString &id, const QString &xref, const QString &value);
        ~GedcomNode();

        QString id() const;
        QString tag() const;
        QString xref() const;
        QString value() const;

        int childCount() const;
        GedcomNode * child(int index) const;
        void addChild(GedcomNode *node);

    private:
        QString _tag, _id, _xref, _value;
        QList<GedcomNode*> _children;
    };
}

#endif // GEDCOMNODE_H
