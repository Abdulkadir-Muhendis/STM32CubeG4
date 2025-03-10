---
pagetitle: Release Notes for STM32 USB-C Power Delivery Core Stack Library
lang: en
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

::: {.card .fluid}
::: {.sectione .dark}
<center>
# <small>Release Notes for</small> STM32 USB-C Power Delivery Core Stack Library
Copyright &copy; 2018 STMicroelectronics\
    
[![ST logo](_htmresc/st_logo.png)](https://www.st.com){.logo}
</center>
:::
:::

# License

This software component is licensed by ST under Ultimate Liberty license SLA0044, the "License"; 
You may not use this component except in compliance with the License. You may obtain a copy of the License at:

[http://www.st.com/SLA0044](http://www.st.com/SLA0044)

# Purpose

The library is provided in binary format, comes on top of the STM32Cube HAL driver and offers all the APIs required to develop an USB PD application.

The USB-PD library is developed following the Universal Serial Bus Power Delivery Specification Revision 3.0, V1.2 (June 06, 2018) and Universal Serial Bus type-C Cable 
and Connector Specification, Revision 1.3 (July 14, 2017). It has passed successfully the official certification.
:::

::: {.col-sm-12 .col-lg-8}
# Update History

::: {.collapse}
<input type="checkbox" id="collapse-section18" checked aria-hidden="true">
<label for="collapse-section18" aria-hidden="true">V2.6.0 / 11-April-2019</label>
<div>

## Main Changes

### Maintenance release


## Contents

  Headline
  --------
  [LOWPOWER] improve dpm core + add deinit interface to usbpd trace
  [LOWPOWER] add interface to update the PE timer according lowpower time
  [PE] Ticket 61818 - [PE] SOP'/SOP'' should be enabled on PRL only if SOP'/SOP" communication is started (not linked to VCONN source) - Bis
  [PE] Ticket 56574 - rework of cable reset management is needed (vconn must be impacted)
  [PE] Ticket 56724 - Cable information (using SOP prime) only works once
  [PE] Ticket 61416 - [PE] Soft reset should be used when extended message received after tSenderResponse
  [PE] Ticket 56545 - Alert data could be overwritten before the PE sent
  [PE] Ticket 57480 - Alert reception can generate an hardfault
  [PE] Enable RX after sending a cable reset
  Ticket 61249 -  Communicate in PD2 with cable if no respond to PD3
  Ticket 61818 - [PE] SOP'/SOP'' should be enabled on PRL only if SOP'/SOP" communication is started (not linked to VCONN source)
  Ticket 60693 - USBPD_HR_STATUS_FAILED needs to be kept
  Ticket 60694 - SINK needs to be able to issue a Hard reset
  [DEF]Ticket 58358 - Missing PPS Power Limited Bit
  [PE] AMS should be started only if message has been sent to port partner
  [PE] PE state machine in should be called immediately during PPS negociation to enter correctly in ready_wait state
  [PE] Fix few MISRA warnings
  [PE] Add Prorocol_error notification in case of wrong received VDM Discovery identity.
  [PE] remove callback trace for VDM specific (move to dpm_user)
  [TRACE] fix trace length (because of a MISRA update)
  [TRACE] wakeup trace process only in task context
  [TRACE] improve the trace system to free CPU time
  update to manage correctly the SwapOngoing in SRC cases
  reset SwapOngoing to avoid CAD lock
  change the way to exit PE task
  USBPD_DPM_IsPowerReady called in SRC and SNK
  Move PDFU files to another folder

  : Fixed bugs list
\

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section17" aria-hidden="true">
<label for="collapse-section17" aria-hidden="true">V2.5.2 / 02-April-2019</label>
<div>

## Main Changes

### Maintenance release


## Contents

  Headline
  --------
  [Ticket 64396]forbidden word detected in usbpdfu_responder.c (files removed from delivery)

  : Fixed bugs list
\

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section16" aria-hidden="true">
<label for="collapse-section16" aria-hidden="true">V2.5.1 / 15-March-2019</label>
<div>

## Main Changes

### Maintenance release


## Contents

  Headline
  --------
  Remove dependencies with CMSIS drivers version  

  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section15" aria-hidden="true">
<label for="collapse-section15" aria-hidden="true">V2.4.0 / 12-Dec-2018 </label>
<div>

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  [USBPD] renaming inside USBPD_SettingsTypeDef
  [USBPD][CORE][DEF] Wrong value for SVDM ATTENTION message
  [USBPD][CORE][PE] Remove return FAIL if no AMA is supported
  [USBPD][CORE][PE] Ticket 55858 - Need notification when ALERT message has been sent by PE
  [USBPD][CORE][PE] Ticket 56156 - ALERT message shouldn't be considered as AMS message
  [USBPD][CORE][PE] Ticket 55899 - [USBPD][PE] Collision avoidance once an Explicit Contract is in place - Third
  [USBPD][CORE][PRL] Add debug switch _PRL_DEBUG_DISABLE_BIST_TRACE (not enabled) to disable BIST message in the traces
  [USBPD][CORE][PE] Minor updates due to compilation issue when __DEBUG_LEVEL is set to 2
  [USBPD][CORE][PE] Disable RX during SNK hard reset sequence
  [USBPD][CORE][PE] Ticket 55984 - SRC3.E25 fail: issue in chuncking tests
  [USBPD][CORE][PE] Ticket 55899 - [USBPD][PE] Collision avoidance once an Explicit Contract is in place
  [USBPD][CORE][DEF] TD.PD.SNK3.E15 Status Fields Check - add power status field in SCB structure
  [USBPD][G0] update to allow the treatment of an incoming message when waiting for sinkTxNG timeout
  [USBPD][G0] increase tsendertimer to 29ms and update the HardReset state change to use notimeout

  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section14" aria-hidden="true">
<label for="collapse-section14" aria-hidden="true"> V2.3.0 / 15-Nov-2018 </label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  [USBPD][CORE] Increase PE Stack size for Authentication configs
  [G0] correction retry patch
  [G0] manage retry according the current spec revision value
  [G0] Patch ellisys test TD.PD.SRC3.E26 Soft reset dend Regarless of Rp value
  [G0] report gotomin + CtrlMessage capability from G0
  [PRL] PD revision should be set to 0 in GoodCRC message only if PD2.0
  add the cable reset tracking inside the tracer
  API update for the following function USBPD_VDM_InformSVID : remove the return which is not tested inside PE USBPD_VDM_InformMode : remove the return which is not tested inside PE USBPD_VDM_InformModeEnter : remove the return which is not tested inside PE USBPD_VDM_SendAttention : remove the return which is not tested inside PE USBPD_VDM_SendSpecific : remove the return which is not tested inside PE USBPD_VDM_InformSpecific : remove the return which is not tested inside PE USBPD_VDM_SendUVDM : remove the return which is not tested inside PE
  Correct wrong destination state in SNK state machine (case PE_SNK_REQUEST_GETSNKCAP_WAITANSWER) : go to PE_SNK_SEND_SOFT_RESET instead of PE_SRC_SEND_SOFT_RESET in case of timeout.
  increase stack size to avoid hardfault with SW4STM32
  Solve one issue in PRL_Received() in case of extended messages. Extended Header was not properly retrieved from RX buffer.
  [3.0] Add battery status management
  [3.0] Authentication : Modifications after end of PlugFest : - Use NOTIMEOUT state update from PE_Sxx_EXTENDEDMESSAGE_SENDING_COMPLETE to PE_Sxx_EXTENDED_WAITRESPONSE in order to avoid losing next chunk request. - Addition of SOPType input parameter in USBPD_PE_SendExtendedMessage() to allow authentication messages to be carried on SOP' - Extension of PE trace buffer from 20 to 30 (useful when chunking is used).
  [3.0] Correction of TD.PD.SRC3.E25 and TD.PD.SNK3.E25 (Receiving Chunked Extended Message)
  [3.0] fix ellisys issue regarding answering NOT_SUPPORTED for SRC_CAPA_EXT in SNK config + NON_SUPPORTED if VDM is not enabled (but test VNDI3.E3 is still failed)
  [3.0] Update SetData and GetData info to provide size in bytes and no more words
  [3.0][PE] Send Not_supported message for DR_SWAP & PR_SWAP in case of SRC only (MQP issues)
  [Core] : Solve critical section issue met on G0 Cut2.0 validation : SRC cap transmitted again despite reception of GoodCRC of previous sending. A critical section has been added before moving in RETRY state.
  [Core] : Update in CMSIS include policy to fit with CMSIS core v4.5 or v5
  [CORE] : update Vconn Support switch name to _VCONN_SUPPORT (as in Application side).
  [CORE] Add missing Extended Message handling in case of SECURITY RESPONSE message type
  [CORE] Align combination of compilation switches used in Collision avoidance functions between H and C
  [CORE] check return on USBPD_DPM_UserInit function
  [CORE] Merge back modifications done for G0 FW v0.9.0 delivery (Stack size updates for PE + CAD, Release_Notes.html)
  [CORE] Move GUI init in GUI_interface module
  [CORE] remove Disable RX during hard reset sequence (fix pb with hard reset on FUSB307 when RX is disabled)
  [CORE] Ticket 53897 - Need to have 'MAX' function as the 'MIN' already present
  [CORE] Ticket 54744 - MQP TD.PD.SRC.E12 Test Failed
  [CORE] Update done for MISRAC2012
  [CORE][DEF] TD.PD.SNK3.E15 Status Fields Check - add power status field in SCB structure
  [CORE][DEF] Wrong value for SVDM ATTENTION message
  [CORE][PE/DPMCORE] : End of Data Role Swap procedure implementation. Solving of SoftReset issue after Datarole swap executed.
  [CORE][PE] Answer to SVDM message only if PE_RespondsToDiscovSOP is enabled
  [CORE][PE] Change state when TPPS timer expires (directly go through PE_SEND_REQUEST) + update lib version to v2.3.0
  [CORE][PE] Disable RX during SNK hard reset sequence
  [CORE][PE] Remove return FAIL if no AMA is supported
  [CORE][PE] Send not supported when VDM enabled in the stack but not in the VIF (DISCO)
  [CORE][PE] Ticket 55858 - Need notification when ALERT message has been sent by PE
  [CORE][PE] Ticket 55899 - [USBPD][PE] Collision avoidance once an Explicit Contract is in place - bis
  [CORE][PE] Ticket 55899 - [USBPD][PE] Collision avoidance once an Explicit Contract is in place - Third
  [CORE][PE] Ticket 55899 - [USBPD][PE] Collision avoidance once an Explicit Contract is in place
  [CORE][PE] Ticket 55984 - SRC3.E25 fail: issue in chuncking tests
  [CORE][PE] Ticket 56156 - ALERT message shouldn't be considered as AMS message
  [CORE][PE] Update for memory optimizations
  [CORE][PRL] : Restore default value for PRL_RETRY_TIMER_VALUE in case of Keil or SW4STM32
  [CORE][PRL] remove 2nd call of USBPD_PHY_IsResistor_SinkTxOk
  [CORE][PRL] Remove interface 'USBPD_PHY_ChannelIdleAfterBusy between PHY & PRL'
  [DPM] Remove semaphore to send message to DPM mailbox
  [DPM] Update DPM param and settings to save Src Extended capa
  [G0] Correct reset of response timer in few state machine
  [G0] Fix Ellisys issue SRC3.E29
  [G0] increase tsendertimer to 29ms and update the HardReset state change to use notimeout
  [G0] remove GUI and User application init, move inside main.c
  [G0] sperate the emb tracer and usbpd application
  [G0] update to allow the treatment of an incoming message when waiting for sinkTxNG timeout
  [G0][PPS] Move start of the timer PE_SRCPPSCommTimer in PE_SRC_READY state
  [G0]Move PE_UnchunkSupport & PE_FastRoleSwapSupport in PD3 structure + add PE_FirmUpdateResponseSupport
  [GUI] Add field in DPM_Settings structure
  [GUI] add PD3 structure
  [GUI] Add USBPD_TRACE_SendNotification API
  [GUI] Integrate _GUI_INTERFACE
  [GUI] Move GUI processing from Core to GUI utilities
  [GUI] Save Data in FLASH
  [MB1357] Add check on VBUS when start SNK
  [PD30] Fix ellisys issues (BATTERY_CAPA + SECURITY REQUEST) + add flag PE_SecuResponseSupport
  [PD30] Modifications done to be able to send GET_SRC_CAPA_EXT message
  [PDO] : 1st step in PDO initialisation rework : Addition of defines usad in APDO values building.
  [PE/PRL] Add interfaces to enable / disable RX + modify callbacks for VDM message ATTENTION
  [PE] Add macro for manage not support or reject message depending
  [PE] Add not supported by GET_SNK_CAPA for SRC
  [PE] Align SNK_READY to SRC_READY state
  [PE] Change VDM specific callbacks
  [PE] fix an issue with SRC extended message
  [PE] Fix Ellisys issue TD.PD.VNDI3.E3 VDM Identity
  [PE] Increase PE_TSNKWAITCAP from 500 to 600 to decrease probability of the test TD4.3.4 but test still failed :-(
  [PE] Need to reset PE variables after hard reset
  [PE] Put again PE_TSNKWAITCAP to 500 as regressions!!!
  [PE] Reset AMS in SRC_READY state
  [PE] Reset PE_HardResetCounter when SRC capa has been received
  [PE] Ticket 36201 - Few modifications to be done in PE stack after review
  [PE] Ticket 52638 - Issue in mode off when product presents default Rp
  [PPS] Fix issues on Ellisys (SCR3.E28, E30, E31...)
  [PPS] Fix issues on Ellisys (SNK.E13, E14)
  [PPS]Reduce value of PE_TPPSTIMEOUT to 14s
  [STACK] Align with modifcations done onb G0
  [STACK] Align with new inclusion model done on G0
  [VCONN] Add USBPD_PE_EvaluateVconnSwap function + change switch from _VCONN_SWAP to _VCONN_SUPPORT
  [VCONN] Evaluate VConn swap in VCONN substate machine
  [VDM] Add check on VDM init function
  [VDM] Change USBPD_VDM_UserInit interface + update functions descriptions
  [VDM] Fix issues on VDM identity and reply to specific
  [VDM] reset PD_Request when Attention message is sent
  [VDM] Wrong return used for USBPD_VDM_UserInit
  [VCONN] start to implement Vconn swap. SNK mode only
  [VDM] Solve MQP PROT-R3-DISCOV test failed on VDM3.E1
  add a function ptr to handle automatic update of the trace if NULL means no trace
  Add support of VCONN and some PD3.0 features (Manufacturer info...)
  considere REJECTED/NOT SUPPORTED valid in case of GETSOURCE_CAP done by source
  correction for gotomin scenario
  correction for TD.PD.SNK3.E12
  correction for VDM3.E2
  correction patch retry
  correction TD.PD.SRC.E3
  DataRole swap test correction
  disable message reception during HARD reset AMS
  Increase PE stack size following crash observed on MQP and Ellisys.
  Lecroy patch TDA 2.2.6 2.2.9
  Lecroy patch TDA.2.2.9 Get Source Cap Receive test
  Merge "[USBPD][PE] Reset PE_HardResetCounter when SRC capa has been received"
  Modifications for VNDI.E7 (Sec Msgs). Still failed on MQP due to GetExtendedSRCCaps request sent by us, but question sent to MQP).
  move CC line assignment before calling DPM_UserCableDetection
  Move trace init after creation of the trace threads
  Notification done with 1 param
  Notification done with only one parameter
  patch TD.PD.DPU.E2 Status Update Command
  PD3.0 manufacturer info management
  PRL alignement with GO
  remove inside PE dpm dependance + lib regeneration
  remove patch to disable RX incompatible with hard reset management
  Ticket 34122 - [DPM] VBUS should be kept enabled when NonPD capable with Rd is present
  Ticket 35350 - Add error recory managment inside USBPD stack
  Update PDO typedefs and constants for reflecting Rev3.0 specs (addition of Unchunk support in PDO Source Fixed, and FRS required current in PDO Sink Fixed).
  update USBPD_PE_Request_CtrlMessage to handle more CTRL message
  Vconn Swap and PD3 integration (Core)


  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section13" aria-hidden="true">
<label for="collapse-section13" aria-hidden="true">V2.2.3 / 12-Sept.-2018</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  Add the check of the value returned by USBPD_DPM_UserInit.
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section12" aria-hidden="true">
<label for="collapse-section12" aria-hidden="true">V2.2.2 / 06-Sept.-2018</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  Corrections done link with tester update Ellisys, MQP, GRP and Lecroy.
  Code improvements
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section11" aria-hidden="true">
<label for="collapse-section11" aria-hidden="true">V2.2.1 / 19-June-2018</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  Correction for compilation warning under Keil IDE.
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section10" aria-hidden="true">
<label for="collapse-section10" aria-hidden="true">V2.2.0 / 20-Apr-2018</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  Alignment between USBPD Core stack delivered in STM32Cube firmware packages and X-Cube USBPD Expansion packages.
  Addition of TCPM feature support. Dedicated libs provided.
  Libraries provided for IAR v7, IAR v8, Keil and SW4STM32.
  Maintenance fixes.
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section9" aria-hidden="true">
<label for="collapse-section9" aria-hidden="true">V2.1.3 / 20-Mars-2018</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  IAR lib compiled with IAR v8.20.2
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section8" aria-hidden="true">
<label for="collapse-section8" aria-hidden="true">V2.1.2 / 22-Jan-2018</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  Add library for SW4STM32 patch
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section7" aria-hidden="true">
<label for="collapse-section7" aria-hidden="true">V2.1.0 / 20-Sep-2017</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  PD3.0 Full.
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section6" aria-hidden="true">
<label for="collapse-section6" aria-hidden="true">V2.1.1 / 8-Dec-2017</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  Patch to accept message not supported in case of data role swap
  Patch to abort AMS power role swap in case of rejection
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section5" aria-hidden="true">
<label for="collapse-section5" aria-hidden="true">V2.0.0 / 13-Sep-2017</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  First official version as element of a STM32Cube FW package.
  Rework in order to enable support of PD3.0 (not activated yet).
  Addition of trace system.
  Reorganization between Core and User/application related code parts and functionalities.
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section4" aria-hidden="true">
<label for="collapse-section4" aria-hidden="true">V1.5.0 / 20-Fev-2017</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  USBPD Core Stack version delivery for X-CUBE-USBPD V2.0.0.
  Code clean-up and code comments review. Code documentation added (Doxygen).  Compilation switch renaming, ...
  Addition of PD3.0 revision support (specific libs created)
  Rework of Application capabilities definition by user : Now handled in new structures to be personalized by user (usbpd_dpm_conf.h, usbpd_dpm_user.h and usbpd_pdo_defs.h files located on User side could be updated).
  New set of libraries delivered :
  PD2 Config_1 : Standard support of PD2.0 (Snk, Source or DRP, 1 or 2 ports, PR Swap, DR Swap, VCONN management support, ...)
  PD2 Full : equal to PD2 Config_1 + support of VDM feature.
  PD3 Config_1 : Standard support of PD3.0 (Snk, Source or DRP, 1 or 2 ports, PR Swap, DR Swap, VCONN management support, support of specific PD3.0 features as ALERT, SRC_CAPA_EXT, STATUS, BATTERY_STATUS, BATTERY_CAPA, MANU_INFO, COUNTRY_MSG messages, support of Extended messages,...) 
  PD3 Full : equal to PD3 Config_1 + support of VDM feature.
  CAD rework with management of event queue.
  Several updates done for fixing issues discovered during continuous integration of Core Stack vs official Conformance test tools (MQP, Ellisys, LeCroy).
  Addition of Trace feature (for debugging purpose).
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::
::: {.collapse}
<input type="checkbox" id="collapse-section3" aria-hidden="true">
<label for="collapse-section3" aria-hidden="true">V1.4.0 / 24-Jul-2017</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  Updates after compliance testing completion on STUSB1602 Device
  Implementation of Error Recovery management
  Code clean, solving of some compilation warnings in SW4STM32.
  [VDM] Addition of API for starting USB Billboard driver.
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section2" aria-hidden="true">
<label for="collapse-section2" aria-hidden="true">V1.2.1 / 24-Apr-2017</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  Second official version after USBPD library split into Core and Device parts. This item only refers to Core stack and is device independent.
  Updates for support of STUSB1602 Device
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section1" aria-hidden="true">
<label for="collapse-section1" aria-hidden="true">V1.2.0 / 16-Jan-2017</label>
<div>      

## Main Changes

### Maintenance release

Maintenance release

## Contents

  Headline
  --------
  First official version after USBPD library split into Core and Device parts. This item only refers to Core stack and is device independent.
  Main Changes compared  to USB-C Power Delivery Library delivered in previous versions 
  Addition of VDM support
  Various corrections in regards with test updates and test additions in USBPD Conformance test tools
  Move PDO definition/capabilities management inside DPM/PWR_IF
  Remove HW dependency with Timerserver (Timerserver feature now handled in Device)
  
  : Fixed bugs list

## known limitations

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V8.20.2
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.25
- System Workbench STM32 (SW4STM32) toolchain V2.7.2

## Supported Devices and boards

## backward compatibility

## Dependencies

</div>
:::

:::
:::

<footer class="sticky">
For complete documentation on STM32,visit: [[www.st.com/stm32](http://www.st.com)]

This release note uses up to date web standards and, for this reason, should not be opened with Internet Explorer
but preferably with popular browsers such as Google Chrome, Mozilla Firefox, Opera or Microsoft Edge.
</footer>
