#!/usr/bin/env bash
# Copyright (c) 2016-2019 The Tokyocoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

TOKYOCOIND=${TOKYOCOIND:-$BINDIR/tokyocoind}
TOKYOCOINCLI=${TOKYOCOINCLI:-$BINDIR/tokyocoin-cli}
TOKYOCOINTX=${TOKYOCOINTX:-$BINDIR/tokyocoin-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/tokyocoin-wallet}
TOKYOCOINQT=${TOKYOCOINQT:-$BINDIR/qt/tokyocoin-qt}

[ ! -x $TOKYOCOIND ] && echo "$TOKYOCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
read -r -a TKCVER <<< "$($TOKYOCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }')"

# Create a footer file with copyright content.
# This gets autodetected fine for tokyocoind if --version-string is not set,
# but has different outcomes for tokyocoin-qt and tokyocoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$TOKYOCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $TOKYOCOIND $TOKYOCOINCLI $TOKYOCOINTX $WALLET_TOOL $TOKYOCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${TKCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${TKCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
