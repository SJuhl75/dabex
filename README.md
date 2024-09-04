Experiments with DAB radio packet data

## Original work from my local hard disk ##
Had to install:
- FFTW3         ->   apt install fftw3-dev
- libfaad       -> apt install libfaad-dev
- libsamplerate -> libsamplerate0-dev
- portaudio     -> portaudio19-dev
- curses.h      -> libncurses5-dev libncursesw5-dev
- ping          -> iputils-ping

192.168.178.61  -> RTL_TCP-Server
/workspaces/codespaces-openvpn/dab3/dab-cmdline/example-5/build/dab-rtl_tcp-5 -H 192.168.178.61

TEST 1: Update Code in Workspace
TEST 2: Update direkt im Repo (hier: im integrierten Editor innerhalb des Repos)
TEST 3b: Parallele Änderung im Repo (analog zu Test 2 -> Commit directly to main Branch)
