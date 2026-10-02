savedcmd_medideliver_driver.mod := printf '%s\n'   medideliver_driver.o | awk '!x[$$0]++ { print("./"$$0) }' > medideliver_driver.mod
