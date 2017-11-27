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
#include "GedcomTest.h"
#include "anselcodec.h"
#include "gedcomparser.h"

#include <QtTest/QtTest>

using namespace cg;

QTEST_MAIN(GedcomTest);

void GedcomTest::initTestCase()
{
    _pTextCodec = new AnselCodec();
}

void GedcomTest::cleanupTestCase()
{
}

void GedcomTest::testAnselAscii()
{
    QByteArray asciiStr;
    for (uchar uc = 1; uc < 0x80; uc++)
        asciiStr.append(uc);

    QTextCodec *pTextCodec = QTextCodec::codecForName("ANSEL");
    QVERIFY(pTextCodec);

    QString uniStr = pTextCodec->toUnicode(asciiStr);
    QByteArray rtStr = pTextCodec->fromUnicode(uniStr);
    QCOMPARE(rtStr, asciiStr);
}

void GedcomTest::testAnselNonAscii()
{
    QByteArray anselStr1 = "\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa\xab\xac\xad\xae";
    QByteArray anselStr2 = "\xb0\xb1\xb2\xb3\xb4\xb5\xb6\xb7\xb8\xb9\xba\xbc\xbd";
    QByteArray anselStr3 = "\xc0\xc1\xc2\xc3\xc4\xc5\xc6";
    QByteArray weRelateStr = "\x81\x88\x89\x92\x93\x94\xc7\xc8\xe8";
    QByteArray gedcomStr = "\xbe\xbf\xcd\xce\xcf";
    // GEDCOM extensions 0xCD and 0xCE map one way to 0x65 and 0x6F respectively
    QByteArray gedcomExpectedStr = "\xbe\xbf\x65\x6f\xcf";

    QTextCodec *pTextCodec = QTextCodec::codecForName("ANSEL");
    QVERIFY(pTextCodec);

    QString uniStr = pTextCodec->toUnicode(anselStr1);
    QByteArray rtStr = pTextCodec->fromUnicode(uniStr);
    QCOMPARE(rtStr, anselStr1);

    uniStr = pTextCodec->toUnicode(anselStr2);
    rtStr = pTextCodec->fromUnicode(uniStr);
    QCOMPARE(rtStr, anselStr2);

    uniStr = pTextCodec->toUnicode(anselStr3);
    rtStr = pTextCodec->fromUnicode(uniStr);
    QCOMPARE(rtStr, anselStr3);

    uniStr = pTextCodec->toUnicode(weRelateStr);
    rtStr = pTextCodec->fromUnicode(uniStr);
    //QCOMPARE(rtStr, weRelateStr);

    uniStr = pTextCodec->toUnicode(gedcomStr);
    rtStr = pTextCodec->fromUnicode(uniStr);
    QCOMPARE(rtStr, gedcomExpectedStr);
}

void GedcomTest::testAnselCombiningDiacritics()
{
    QByteArray anselStr1 = "\xE0\x41";

    QTextCodec *pTextCodec = QTextCodec::codecForName("ANSEL");
    QVERIFY(pTextCodec);

    QString uniStr = pTextCodec->toUnicode(anselStr1);
    QByteArray rtStr = pTextCodec->fromUnicode(uniStr);
    QCOMPARE(rtStr, anselStr1);
}

void GedcomTest::testParser()
{
    GedcomParser parser;
    QString encoding;
    QString dataDir = qgetenv("CGGEDCOM_DATA_DIR");

    // Kennedy Family
    QString kennedyFile = dataDir + "\\The Kennedy Family.ged";

    QFileInfo fi1(kennedyFile);
    QVERIFY(fi1.exists());

    QVERIFY(parser.getEncoding(kennedyFile, encoding));
    QCOMPARE(encoding, QString("ANSEL"));

    parser.parse(kennedyFile);
    GedcomParser::NodeList indiList = parser.nodesWithTag("INDI");
    QCOMPARE(indiList.size(), 69);

    // Kings & Queens
    QString kingsAndQueensFile = dataDir + "\\The English and British Kings and Queens.ged";

    QFileInfo fi2(kingsAndQueensFile);
    QVERIFY(fi2.exists());

    parser.parse(kingsAndQueensFile);
    indiList = parser.nodesWithTag("INDI");
    QCOMPARE(indiList.size(), 158);

    // BibleFamilyTree
    QString bibleFile = dataDir + "\\BibleFamilyTree.ged";

    QFileInfo fi3(bibleFile);
    QVERIFY(fi3.exists());

    parser.parse(bibleFile);
    indiList = parser.nodesWithTag("INDI");
    QCOMPARE(indiList.size(), 583);
}



