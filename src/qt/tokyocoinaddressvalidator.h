// Copyright (c) 2011-2014 The Tokyocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TOKYOCOIN_QT_TOKYOCOINADDRESSVALIDATOR_H
#define TOKYOCOIN_QT_TOKYOCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class TokyocoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TokyocoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** Tokyocoin address widget validator, checks for a valid tokyocoin address.
 */
class TokyocoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit TokyocoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // TOKYOCOIN_QT_TOKYOCOINADDRESSVALIDATOR_H
