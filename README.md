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