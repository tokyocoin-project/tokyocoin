// Copyright (c) 2009-2015 The Tokyocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TOKYOCOIN_QT_TEST_URITESTS_H
#define TOKYOCOIN_QT_TEST_URITESTS_H

#include <QObject>
#include <QTest>

class URITests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void uriTests();
};

#endif // TOKYOCOIN_QT_TEST_URITESTS_H
