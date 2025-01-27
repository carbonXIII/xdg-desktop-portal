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

#include "clipboard-provider.h"

G_DEFINE_INTERFACE(ClipboardProvider, clipboard_provider, G_TYPE_OBJECT)

void clipboard_provider_default_init(ClipboardProviderInterface *) {}

gboolean
clipboard_provider_can_request (ClipboardProvider *self)
{
  ClipboardProviderInterface *iface = CLIPBOARD_PROVIDER_GET_IFACE (self);
  g_return_val_if_fail (iface->can_request != NULL, FALSE);
  return iface->can_request (self);
}

gboolean
clipboard_provider_is_enabled (ClipboardProvider *self)
{
  ClipboardProviderInterface *iface = CLIPBOARD_PROVIDER_GET_IFACE (self);
  g_return_val_if_fail (iface->is_enabled != NULL, FALSE);
  return iface->is_enabled (self);
}

void
clipboard_provider_requested (ClipboardProvider *self)
{
  ClipboardProviderInterface *iface = CLIPBOARD_PROVIDER_GET_IFACE (self);
  g_return_if_fail (iface->requested != NULL);
  iface->requested (self);
}
