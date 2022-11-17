# Sync Global Rackspace Plugin with Local Rackspace Plugin

## Overview
Small test extension for Gig Performer that uses the GP Script 'handles' to link a global rackspace plugin to a local rackspace plugin, and then sync their parameter values (local plugin is the master) when the rackspace is first activated.

## Usage
Add a GP Script handle to a local rackspace plugin in the format:
```
 LOCAL_1
 ```
Add a matching GP Script handle to a global rackspace plugin in the format:
```
 GLOBAL_1
 ```

 When switching to the local rackspace, the global plugin will be updated to match the parameter values of the local plugin.

 The above handle format can be repeated for as many plugins as you need to sync.

 ## Installation

Download the extension (library) files for either MacOS or Windows from the [Releases](https://github.com/gp-rank13/gp-pluginsync/releases) page.  

Mac users will need to move the _dylib_ file into this folder and then restart Gig Performer:
```
/Users/Shared/Gig Performer/Extensions
```
Windows users will need to move the _dll_ file into this folder and then restart Gig Performer:
```
C:\Users\Public\Documents\Gig Performer\Extensions
```
When opening Gig Perfomer, a prompt will appear asking to confirm whether to install the extension.