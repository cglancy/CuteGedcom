/**
* Copyright 2017 Charles Glancy (charles@glancyfamily.net)
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
#ifndef CUTEGEDCOM_GEDCOMPARSER_H
#define CUTEGEDCOM_GEDCOMPARSER_H
#pragma once

#include "cutegedcom.h"
#include <QString>
#include <QMap>
#include <QList>

namespace CuteGedcom
{
    class GedcomNode;

    class CUTEGEDCOM_API GedcomParser
    {
    public:
        typedef QList<GedcomNode*> NodeList;

    public:
        GedcomParser();
        ~GedcomParser();

        void clear();

        bool getEncoding(const QString &filename, QString &encoding);

        void parse(const QString &filename);
        GedcomNode * rootNode() const;
        GedcomNode * node(const QString &id) const;
        NodeList nodesWithTag(const QString &tag) const;

    private:
        QString getCorrectedEncoding(const QString &source, const QString &encoding, const QString &version);

    private:
        GedcomNode *_rootNode;
        QMap<QString, GedcomNode*> _nodeMap;
    };
}

#endif // CUTEGEDCOM_GEDCOMPARSER_H
