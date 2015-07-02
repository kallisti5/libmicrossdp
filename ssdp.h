/*
 * libmicrossdp
 * Copyright 2014-2015 Alexander von Gluck IV <kallisti5@unixzen.com>
 * Released under the terms of the MIT license
 *
 * Authors:
 *	Alexander von Gluck IV <kallisti5@unixzen.com>
 */
#ifndef INCLUDE_SSDP_H
#define INCLUDE_SSDP_H


/* Category of device */
#define SSDP_CAT_BASIC				(0 << 0)
#define SSDP_CAT_AV					(0 << 1)
#define SSDP_CAT_DATASTORE			(1 << 1)
#define SSDP_CAT_DEVICEMANAGEMENT	(1 << 2)
#define SSDP_CAT_FRIENDLYDEVICES	(1 << 3)
#define SSDP_CAT_HOMEAUTOMATION		(1 << 4)
#define SSDP_CAT_IOTMANAGEMENT		(1 << 5)
#define SSDP_CAT_MULTISCREEN		(1 << 6)
#define SSDP_CAT_NETWORKING			(1 << 7)
#define SSDP_CAT_TELEPHONY			(1 << 8)	
#define SSDP_CAT_PRINTER			(1 << 9)	
#define SSDP_CAT_REMOTEACCESS		(1 << 10)	
#define SSDP_CAT_REMOTING			(1 << 11)	
#define SSDP_CAT_SCANNER			(1 << 12)	
#define SSDP_CAT_CONTENTSYNC		(1 << 13)	
#define SSDP_CAT_SECURITY			(1 << 14)	
#define SSDP_CAT_LOWPOWER			(1 << 15)	
#define SSDP_CAT_QOS				(1 << 16)	

#define URN_SCHEMA_DEVICE			"urn:schemas-upnp-org:device:"
#define SSDP_PACKET_BUFFER			1024

/* Device definitions */
const struct upnp_dcp {
	unsigned int	category;
	const char*		type;
} kKnownDCP[] = {
	{SSDP_CAT_AV,				"MediaServer:1"},
	{SSDP_CAT_AV,				"MediaServer:2"},
	{SSDP_CAT_AV,				"MediaServer:3"},
	{SSDP_CAT_AV,				"MediaServer:4"},
	{SSDP_CAT_AV,				"MediaRenderer:1"},
	{SSDP_CAT_AV,				"MediaRenderer:2"},
	{SSDP_CAT_AV,				"MediaRenderer:3"},
	{SSDP_CAT_BASIC,			"Basic:1"},
	{SSDP_CAT_DATASTORE,		"DataStore:1"},
	{SSDP_CAT_DEVICEMANAGEMENT,	"DeviceManagment:1"},
	{SSDP_CAT_DEVICEMANAGEMENT,	"DeviceManagment:2"},
	{SSDP_CAT_HOMEAUTOMATION,	"SolarProtectionBlind:1"},
	{SSDP_CAT_HOMEAUTOMATION,	"LightingControls:1"},
	{SSDP_CAT_HOMEAUTOMATION,	"HVAC:1"},
	{SSDP_CAT_HOMEAUTOMATION,	"DigitalSecurityCamera:1"},
	{SSDP_CAT_IOTMANAGEMENT,	"IoTManagementAndControlArchitecture:1"},
	{SSDP_CAT_MULTISCREEN,		"ScreenDevice:1"},
	{SSDP_CAT_MULTISCREEN,		"ScreenDevice:2"},
	// TODO: Networking
	{SSDP_CAT_TELEPHONY,		"Telephony:1"},
	{SSDP_CAT_TELEPHONY,		"Telephony:2"},
	{SSDP_CAT_PRINTER,			"Printer:1"}
	// TODO: Remote Access
	// TODO: Remoting
	// TODO: Scanner
	// TODO: Content Sync
	// TODO: Security
	// TODO: Low Power
	// TODO: QOS
};


struct upnp_device {
	unsigned int    category;
	const char*     type;
	const char*		url;
	const char*		ip;
};


struct upnp_device* ssdp_discovery(int family, int wait, unsigned int category);


#endif /*INCLUDE_SSDP_H*/