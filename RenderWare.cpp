#include "../../main.h"
#include "RenderWare.h"

RsGlobalType* RsGlobal;

/* rwcore.h */
RwCamera* 	(*RwCameraCreate)(void);
RwCamera*	(*RwCameraClear)(RwCamera* camera, RwRGBA* rgba, RwInt32 i);
RwCamera* 	(*RwCameraBeginUpdate)(RwCamera* camera);
RwCamera* 	(*RwCameraEndUpdate)(RwCamera* camera);
RwCamera* 	(*RwCameraShowRaster)(RwCamera * camera, void *pDev, RwUInt32 flags);
RwCamera*	(*RwCameraSetFarClipPlane)(RwCamera* camera, RwReal f);
RwCamera*	(*RwCameraSetNearClipPlane)(RwCamera* camera, RwReal f);
RwCamera*	(*RwCameraSetViewWindow)(RwCamera* camera, const RwV2d* v);
RwCamera*	(*RwCameraSetProjection)(RwCamera* camera, int projection);
RwBool		(*RwCameraFrustumTestSphere)(RwCamera* camera, RwSphere* sphere);

RwFrame* 	(*RwFrameCreate)(void);
RwFrame*	(*RwFrameTranslate)(RwFrame* rwFrame, const RwV3d* v, int type);
RwFrame*	(*RwFrameRotate)(RwFrame* rwFrame, const RwV3d* v, RwReal rot, int type);
RwFrame* 	(*RwFrameForAllObjects)(RwFrame* rwFrame, void* callBack, void* data);

RpLight*	(*RpLightCreate)(RwInt32 type);
RpLight* 	(*RpLightSetColor)(RpLight* rpLight, RwRGBAReal const* v);

RwRaster* 	(*RwRasterCreate)(RwInt32 width, RwInt32 height, RwInt32 depth, RwInt32 flags);
RwBool 		(*RwRasterDestroy)(RwRaster * raster);
RwRaster* 	(*RwRasterGetOffset)(RwRaster *raster, RwInt16 *xOffset, RwInt16 *yOffset);
RwInt32 	(*RwRasterGetNumLevels)(RwRaster * raster);
RwRaster* 	(*RwRasterSubRaster)(RwRaster * subRaster, RwRaster * raster, RwRect * rect);
RwRaster* 	(*RwRasterRenderFast)(RwRaster * raster, RwInt32 x, RwInt32 y);
RwRaster* 	(*RwRasterRender)(RwRaster * raster, RwInt32 x, RwInt32 y);
RwRaster* 	(*RwRasterRenderScaled)(RwRaster * raster, RwRect * rect);
RwRaster* 	(*RwRasterPushContext)(RwRaster * raster);
RwRaster* 	(*RwRasterPopContext)(void);
RwRaster* 	(*RwRasterGetCurrentContext)(void);
RwBool 		(*RwRasterClear)(RwInt32 pixelValue);
RwBool 		(*RwRasterClearRect)(RwRect * rpRect, RwInt32 pixelValue);
RwRaster* 	(*RwRasterShowRaster)(RwRaster * raster, void *dev, RwUInt32 flags);
RwUInt8* 	(*RwRasterLock)(RwRaster * raster, RwUInt8 level, RwInt32 lockMode);
RwRaster* 	(*RwRasterUnlock)(RwRaster * raster);
RwUInt8* 	(*RwRasterLockPalette)(RwRaster * raster, RwInt32 lockMode);
RwRaster* 	(*RwRasterUnlockPalette)(RwRaster * raster);
RwImage* 	(*RwImageCreate)(RwInt32 width, RwInt32 height, RwInt32 depth);
RwBool 		(*RwImageDestroy)(RwImage * image);
RwImage* 	(*RwImageAllocatePixels)(RwImage * image);
RwImage* 	(*RwImageFreePixels)(RwImage * image);
RwImage* 	(*RwImageCopy)(RwImage * destImage, const RwImage * sourceImage);
RwImage* 	(*RwImageResize)(RwImage * image, RwInt32 width, RwInt32 height);
RwImage* 	(*RwImageApplyMask)(RwImage * image, const RwImage * mask);
RwImage* 	(*RwImageMakeMask)(RwImage * image);
RwImage* 	(*RwImageReadMaskedImage)(const RwChar * imageName, const RwChar * maskname);
RwImage* 	(*RwImageRead)(const RwChar * imageName);
RwImage* 	(*RwImageWrite)(RwImage * image, const RwChar * imageName);
RwImage* 	(*RwImageSetFromRaster)(RwImage *image, RwRaster *raster);
RwRaster* 	(*RwRasterSetFromImage)(RwRaster *raster, RwImage *image);
RwRaster* 	(*RwRasterRead)(const RwChar *filename);
RwRaster* 	(*RwRasterReadMaskedRaster)(const RwChar *filename, const RwChar *maskname);
RwImage* 	(*RwImageFindRasterFormat)(RwImage *ipImage, RwInt32 nRasterType, RwInt32 *npWidth, RwInt32 *npHeight, RwInt32 *npDepth,RwInt32 *npFormat);

/* rpworld.h */
RpWorld*	(*RpWorldAddCamera)(RpWorld* world, RwCamera* camera);
RpWorld*	(*RpWorldAddLight)(RpWorld* world, RpLight* light);
RpWorld*	(*RpWorldRemoveLight)(RpWorld* world, RpLight* light);

/* rwlpcore.h */
RwReal 		(*RwIm2DGetNearScreenZ)(void);
RwReal 		(*RwIm2DGetFarScreenZ)(void);
RwBool 		(*RwRenderStateGet)(RwRenderState state, void *value);
RwBool 		(*RwRenderStateSet)(RwRenderState state, void *value);
RwBool 		(*RwIm2DRenderLine)(RwIm2DVertex *vertices, RwInt32 numVertices, RwInt32 vert1, RwInt32 vert2);
RwBool 		(*RwIm2DRenderTriangle)(RwIm2DVertex *vertices, RwInt32 numVertices, RwInt32 vert1, RwInt32 vert2, RwInt32 vert3 );
RwBool 		(*RwIm2DRenderPrimitive)(RwPrimitiveType primType, RwIm2DVertex *vertices, RwInt32 numVertices);
RwBool 		(*RwIm2DRenderIndexedPrimitive)(RwPrimitiveType primType, RwIm2DVertex *vertices, RwInt32 numVertices, RwImVertexIndex *indices, RwInt32 numIndices);

RwObject*   (*RwObjectHasFrameSetFrame)(RwCamera* camera, RwFrame* rwFrame);

/* rtpng.h */
RwImage*	(*RtPNGImageWrite)(RwImage* image, const RwChar* imageName);
RwImage* 	(*RtPNGImageRead)(const RwChar* imageName);

RwTexture*	(*RwTextureCreate)(RwRaster* raster);
RwTexture* 	(*RwTextureRead)(const RwChar *filename, const RwChar *imageName);
RwTexture* 	(*RwTextureDestroy)(RwTexture *rwTexture);
RwTexture* 	(*RwTextureSetName)(RwTexture *rwTexture, const char *name);

void InitRenderWareFunctions()
{
	Log("Initializing RenderWare..");

	/* skeleton.h */
	RsGlobal = (RsGlobalType*)(g_libGTASA+0x9FC8FC);

	/* rwCore.h */
	*(void**)(&RwCameraCreate)					= (void*)(g_libGTASA+0x1D5F60+1);
	*(void**)(&RwCameraClear) 					= (void*)(g_libGTASA+0x1D5D70+1);
	*(void**)(&RwCameraBeginUpdate) 			= (void*)(g_libGTASA+0x1D5A98+1);
	*(void**)(&RwCameraEndUpdate) 				= (void*)(g_libGTASA+0x1D5A94+1);
	*(void**)(&RwCameraShowRaster)				= (void*)(g_libGTASA+0x1D5D94+1);
	*(void**)(&RwCameraSetFarClipPlane)			= (void*)(g_libGTASA+0x1D5B4C+1);
	*(void**)(&RwCameraSetNearClipPlane)		= (void*)(g_libGTASA+0x1D5AB8+1);
	*(void**)(&RwCameraSetViewWindow)			= (void*)(g_libGTASA+0x1D5E84+1);
	*(void**)(&RwCameraSetProjection)			= (void*)(g_libGTASA+0x1D5DA8+1);
	*(void**)(&RwCameraFrustumTestSphere)		= (void*)(g_libGTASA+0x1D5BE0+1);

	*(void**)(&RwFrameCreate) 					= (void*)(g_libGTASA+0x1D822C+1);
	*(void**)(&RwFrameTranslate) 				= (void*)(g_libGTASA+0x1D8694+1);
	*(void**)(&RwFrameRotate)					= (void*)(g_libGTASA+0x1D87A8+1);
	*(void**)(&RwFrameForAllObjects)			= (void*)(g_libGTASA+0x1D88D8+1);

	*(void**)(&RpLightCreate) 					= (void*)(g_libGTASA+0x216E30+1);
	*(void**)(&RpLightSetColor) 				= (void*)(g_libGTASA+0x2167C6+1);

	*(void **)(&RwRasterCreate) 				= (void*)(g_libGTASA+0x1DAA50+1);
	*(void **)(&RwRasterDestroy) 				= (void*)(g_libGTASA+0x1DA850+1);
	*(void **)(&RwRasterGetOffset) 				= (void*)(g_libGTASA+0x1DA72C+1);
	*(void **)(&RwRasterGetNumLevels) 			= (void*)(g_libGTASA+0x1DA980+1);
	*(void **)(&RwRasterSubRaster) 				= (void*)(g_libGTASA+0x1DA9F4+1);
	*(void **)(&RwRasterRenderFast)				= (void*)(g_libGTASA+0x1DA7B4+1);
	*(void **)(&RwRasterRender)					= (void*)(g_libGTASA+0x1DA800+1);
	*(void **)(&RwRasterRenderScaled)			= (void*)(g_libGTASA+0x1DA70C+1);
	*(void **)(&RwRasterPushContext)			= (void*)(g_libGTASA+0x1DA898+1);
	*(void **)(&RwRasterPopContext)				= (void*)(g_libGTASA+0x1DA938+1);
	*(void **)(&RwRasterGetCurrentContext)		= (void*)(g_libGTASA+0x1DA6EC+1);
	*(void **)(&RwRasterClear)					= (void*)(g_libGTASA+0x1DA75C+1);
	*(void **)(&RwRasterClearRect)				= (void*)(g_libGTASA+0x1DA7E0+1);
	*(void **)(&RwRasterShowRaster)				= (void*)(g_libGTASA+0x1DA9BC+1);
	*(void **)(&RwRasterLock)					= (void*)(g_libGTASA+0x1DAB24+1);
	*(void **)(&RwRasterUnlock)					= (void*)(g_libGTASA+0x1DA738+1);
	*(void **)(&RwRasterLockPalette)			= (void*)(g_libGTASA+0x1DA90C+1);
	*(void **)(&RwRasterUnlockPalette)			= (void*)(g_libGTASA+0x1DA82C+1);
	*(void **)(&RwImageCreate)					= (void*)(g_libGTASA+0x1D8EA0+1);
	*(void **)(&RwImageDestroy)					= (void*)(g_libGTASA+0x1D8EF8+1);
	*(void **)(&RwImageAllocatePixels)			= (void*)(g_libGTASA+0x1D8F84+1);
	*(void **)(&RwImageFreePixels)				= (void*)(g_libGTASA+0x1D8F58+1);
	*(void **)(&RwImageCopy)					= (void*)(g_libGTASA+0x1D95E0+1);
	*(void **)(&RwImageResize)					= (void*)(g_libGTASA+0x1D9020+1);
	*(void **)(&RwImageApplyMask)				= (void*)(g_libGTASA+0x1D9300+1);
	*(void **)(&RwImageMakeMask)				= (void*)(g_libGTASA+0x1D9148+1);
	*(void **)(&RwImageReadMaskedImage)			= (void*)(g_libGTASA+0x1D9E5C+1);
	*(void **)(&RwImageRead)					= (void*)(g_libGTASA+0x1D982C+1);
	*(void **)(&RwImageWrite)					= (void*)(g_libGTASA+0x1D9DC0+1);
	*(void **)(&RwImageSetFromRaster)			= (void*)(g_libGTASA+0x1DA4D4+1);
	*(void **)(&RwRasterSetFromImage)			= (void*)(g_libGTASA+0x1DA4F8+1);
	*(void **)(&RwRasterRead)					= (void*)(g_libGTASA+0x1DA5F4+1);
	*(void **)(&RwRasterReadMaskedRaster)		= (void*)(g_libGTASA+0x1DA694+1);
	*(void **)(&RwImageFindRasterFormat)		= (void*)(g_libGTASA+0x1DA51C+1);

	/* rpworld.h */
	*(void **)(&RpWorldAddCamera)				= (void*)(g_libGTASA+0x21E004+1);
	*(void **)(&RpWorldAddLight)				= (void*)(g_libGTASA+0x21E830+1);
	*(void **)(&RpWorldRemoveLight)				= (void*)(g_libGTASA+0x21E830+1);

	/* rwlpcore.h */
	*(void **)(&RwIm2DGetNearScreenZ)			= (void*)(g_libGTASA+0x1E28F4+1);
	*(void **)(&RwIm2DGetFarScreenZ)			= (void*)(g_libGTASA+0x1E2904+1);
	*(void **)(&RwRenderStateGet)				= (void*)(g_libGTASA+0x1E2948+1);
	*(void **)(&RwRenderStateSet)				= (void*)(g_libGTASA+0x1E2914+1);
	*(void **)(&RwIm2DRenderLine)				= (void*)(g_libGTASA+0x1E2958+1);
	*(void **)(&RwIm2DRenderTriangle)			= (void*)(g_libGTASA+0x1E2970+1);
	*(void **)(&RwIm2DRenderPrimitive)			= (void*)(g_libGTASA+0x1E2988+1);
	*(void **)(&RwIm2DRenderIndexedPrimitive)	= (void*)(g_libGTASA+0x1E2998+1);

	*(void **)(&RwObjectHasFrameSetFrame)		= (void*)(g_libGTASA+0x1DCFE4+1);

	/* rtpng.h */
	*(void **)(&RtPNGImageWrite)				= (void*)(g_libGTASA+0x20A1C4+1);
	*(void **)(&RtPNGImageRead)					= (void*)(g_libGTASA+0x20A474+1);
	
	*(void **)(&RwTextureCreate) 				= (void*)(g_libGTASA+0x1DB83C+1);
	*(void **)(&RwTextureRead)					= (void*)(g_libGTASA+0x1DBABC+1);
	*(void **)(&RwTextureDestroy)				= (void*)(g_libGTASA+0x1DB764+1);
	*(void **)(&RwTextureSetName)				= (void*)(g_libGTASA+0x1DB8A0+1);
}