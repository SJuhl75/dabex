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
TEST 3a: Erneute Änderung im Workspace
TEST 3b: Parallele Änderung im Repo (analog zu Test 2 -> Commit directly to main Branch)
TEST 4: Einschub im Repo
.. 4a: Einschub im Codespace
... 4b: im Repo
<<<<<<< HEAD
... 4d im Repo
=======
... 4c: im Codespace
>>>>>>> e0307c7 ("Codespace bestimmt, wo es lang geht, Automerge ist kein Allheilmittel und kann auch zu)
TEST 5: Wo ist 3a hin?
