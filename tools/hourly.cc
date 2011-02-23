
#include <stdlib.h>

#include <snapper/Snapper.h>
#include <snapper/Factory.h>

using namespace snapper;


int
main(int argc, char** argv)
{
    if (argc != 2)
    {
	fprintf(stderr, "usage: hourly root\n");
	exit(EXIT_FAILURE);
    }

    string root = argv[1];

    if (root != "/")		// TODO
	exit(EXIT_SUCCESS);

    Snapper* sh = createSnapper(root);

    Snapshots::iterator snap = sh->createSingleSnapshot("timeline");
    snap->setCleanup("timeline");

    deleteSnapper(sh);

    exit(EXIT_SUCCESS);
}