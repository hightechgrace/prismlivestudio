#pragma once

#if defined(_WIN32)
#include <DeckLinkAPI.h>
//PRISM/LiuHaibin/20200316/#1641/decklink code from OBS
#include "win/decklink-sdk/DeckLinkAPIVersion.h"
typedef BOOL decklink_bool_t;
typedef BSTR decklink_string_t;
IDeckLinkDiscovery *CreateDeckLinkDiscoveryInstance(void);
//PRISM/LiuHaibin/20200316/#1641/decklink code from OBS
IDeckLinkIterator *CreateDeckLinkIteratorInstance(void);
#define IUnknownUUID IID_IUnknown
typedef REFIID CFUUIDBytes;
#define CFUUIDGetUUIDBytes(x) x
#elif defined(__APPLE__)
#include "mac/decklink-sdk/DeckLinkAPI.h"
#include "mac/decklink-sdk/DeckLinkAPIVersion.h"
//PRISM/LiuHaibin/20200316/#1641/decklink code from OBS
#include <CoreFoundation/CoreFoundation.h>
typedef bool decklink_bool_t;
typedef CFStringRef decklink_string_t;
#elif defined(__linux__)
#include "linux/decklink-sdk/DeckLinkAPI.h"
//PRISM/LiuHaibin/20200316/#1641/decklink code from OBS
#include "linux/decklink-sdk/DeckLinkAPIVersion.h"
typedef bool decklink_bool_t;
typedef const char *decklink_string_t;
#endif

#include <util/windows/HRError.hpp>
#include <util/windows/ComPtr.hpp>

#include <string>

bool DeckLinkStringToStdString(decklink_string_t input, std::string &output);