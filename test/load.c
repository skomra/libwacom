/*
 * Copyright © 2011 Red Hat, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose is hereby granted without
 * fee, provided that the above copyright notice appear in all copies
 * and that both that copyright notice and this permission notice
 * appear in supporting documentation, and that the name of Red Hat
 * not be used in advertising or publicity pertaining to distribution
 * of the software without specific, written prior permission.  Red
 * Hat makes no representations about the suitability of this software
 * for any purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * THE AUTHORS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN
 * NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Authors:
 *	Peter Hutterer (peter.hutterer@redhat.com)
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <string.h>
#include "libwacom.h"
#include <assert.h>

int main(int argc, char **argv)
{
    WacomDevice *device;
    const char *str;

    device = libwacom_new_from_usbid(0, 0, NULL);
    assert(!device);

    device = libwacom_new_from_usbid(0x56a, 0x00bc, NULL);
    assert(device);

    str = libwacom_get_vendor(device);
    assert(strcmp(str, "Wacom") == 0);
    assert(libwacom_get_class(device) == WCLASS_INTUOS4);
    assert(libwacom_get_vendor_id(device) == 0x56a);
    assert(libwacom_get_product_id(device) == 0xbc);
    assert(libwacom_get_bustype(device) == WBUSTYPE_USB);
    assert(libwacom_get_num_buttons(device) == 9);
    assert(libwacom_has_stylus(device));
    assert(!libwacom_has_touch(device));
    assert(libwacom_has_ring(device));
    assert(!libwacom_has_ring2(device));
    assert(!libwacom_has_vstrip(device));
    assert(!libwacom_has_hstrip(device));
    assert(!libwacom_is_builtin(device));
    assert(libwacom_get_width(device) == 9);
    assert(libwacom_get_height(device) == 6);

    libwacom_destroy(&device);
    assert(!device);

    return 0;
}

/* vim: set noexpandtab tabstop=8 shiftwidth=8: */
