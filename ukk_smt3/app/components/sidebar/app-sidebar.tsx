import {
  Sidebar,
  SidebarContent,
  SidebarFooter,
  SidebarGroup,
  SidebarGroupContent,
  SidebarGroupLabel,
  SidebarHeader,
  SidebarMenu,
  SidebarMenuButton,
  SidebarMenuItem,
} from "@/components/ui/sidebar";
import {
  LayoutDashboard,
  GraduationCap,
  ChartBarStacked,
  FileText,
  SquareUser,
  UsersRound,
} from "lucide-react";
import Image from "next/image";
import Link from "next/link";

export function AppSidebar() {
  return (
    <Sidebar className="border-r-0 [&>div]:bg-pink-200 [&>div]:text-white">
      <div className="flex h-full w-full flex-col bg-pink-200 text-white">
        {/* Header Logo */}
        <SidebarHeader className="p-4 bg-pink-200">
          {/* <div className="flex items-center justify-center gap-3 px-3 py-2">
            <Image
              src="#"
              alt="#"
              width={200}
              height={200}
              className="w-auto h-auto max-h-12 object-contain"
              priority
            />
          </div> */}
        </SidebarHeader>

        {/* Content Menu */}
        <SidebarContent className="bg-pink-200">
          <SidebarGroup>
            <SidebarGroupLabel className="text-white/80 text-xs font-semibold px-2 mb-2">
              Menu Utama
            </SidebarGroupLabel>
            <SidebarGroupContent>
              <SidebarMenu>
                {/* Dashboard */}
                <SidebarMenuItem>
                  <SidebarMenuButton
                    asChild
                    className="text-white hover:bg-pink-200 hover:text-white active:bg-pink-200"
                  >
                    <Link href="/admin">
                      <LayoutDashboard className="w-4 h-4 mr-2" />
                      <span>Dashboard</span>
                    </Link>
                  </SidebarMenuButton>
                </SidebarMenuItem>

                <SidebarMenuItem>
                  <SidebarMenuButton
                    asChild
                    className="text-white hover:bg-pink-200 hover:text-white active:bg-pink-200"
                  >
                    <Link href="/admin/user-management">
                      <UsersRound className="w-4 h-4 mr-2" />
                      <span>User Management</span>
                    </Link>
                  </SidebarMenuButton>
                </SidebarMenuItem>

                <SidebarMenuItem>
                  <SidebarMenuButton
                    asChild
                    className="text-white hover:bg-pink-200 hover:text-white active:bg-pink-200"
                  >
                    <Link href="/admin/tabel">
                      <UsersRound className="w-4 h-4 mr-2" />
                      <span>Tabel</span>
                    </Link>
                  </SidebarMenuButton>
                </SidebarMenuItem>
  
              </SidebarMenu>
            </SidebarGroupContent>
          </SidebarGroup>
        </SidebarContent>

        <SidebarFooter className="bg-pink-200" />
      </div>
    </Sidebar>
  );
}