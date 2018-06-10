### Publish to AUR

 - Update version in AUR/PKGBUILD and AUR/.SRCINFO (or regenerate with `makepkg --printsrcinfo`)
 - Stage and commit in AUR (it is a submodule) `cd AUR && git add . && git commit`
 - In project root, stage and commmit the AUR submodule link
 - Push project root to github
 - Create the version tag on github
 - Change to AUR submodule and push previous commit to AUR `git push` 
