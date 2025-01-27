/*
 * Copyright 2025 Jordan Richards
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include <glib-object.h>

G_BEGIN_DECLS

#define CLIPBOARD_TYPE_PROVIDER clipboard_provider_get_type ()
G_DECLARE_INTERFACE (ClipboardProvider, clipboard_provider, CLIPBOARD, PROVIDER, GObject)

struct _ClipboardProviderInterface {
  GTypeInterface parent_iface;

  gboolean (*can_request) (ClipboardProvider *self);
  gboolean (*is_enabled) (ClipboardProvider *self);
  void (*requested) (ClipboardProvider *self);
};

G_END_DECLS

gboolean clipboard_provider_can_request (ClipboardProvider *self);
gboolean clipboard_provider_is_enabled (ClipboardProvider *self);
void clipboard_provider_requested (ClipboardProvider *self);
